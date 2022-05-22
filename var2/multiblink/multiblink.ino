// multiblink.ino - sketch to blink 5 LEDs randomly (multiple modes and speeds)
// https://github.com/SpenceKonde/ATTinyCore


// === led ========================================


#define LED_0       1
#define LED_1       2
#define LED_2       4
#define LED_3       8
#define LED_4      16
#define LED_ALL    31


#if 0 // Nano
  #define LED_0_PIN   2
  #define LED_1_PIN   3
  #define LED_2_PIN   4
  #define LED_3_PIN   5
  #define LED_4_PIN   6
#endif
#if 1 // ATtiny
  #define LED_0_PIN   0
  #define LED_1_PIN   1
  #define LED_2_PIN   2
  #define LED_3_PIN   3
  #define LED_4_PIN   4
#endif


void led_init() {
  pinMode( LED_0_PIN, OUTPUT );
  pinMode( LED_1_PIN, OUTPUT );
  pinMode( LED_2_PIN, OUTPUT );
  pinMode( LED_3_PIN, OUTPUT );
  pinMode( LED_4_PIN, OUTPUT );
}


void led_set(uint8_t leds ) {
  digitalWrite( LED_0_PIN, (leds&0x01)==0 );
  digitalWrite( LED_1_PIN, (leds&0x02)==0 );
  digitalWrite( LED_2_PIN, (leds&0x04)==0 );
  digitalWrite( LED_3_PIN, (leds&0x08)==0 );
  digitalWrite( LED_4_PIN, (leds&0x10)==0 );
  
}


// === but ========================================


#define BUT_0       1
#define BUT_1       2
#define BUT_ALL     3


#define BUT_0_PIN   LED_0_PIN
#define BUT_1_PIN   LED_4_PIN


// Call but_scan() in every loop
uint8_t  but_prv;  // button state in previous call to but_scan()
uint8_t  but_cur;  // button state in current call to but_scan()


void but_scan() {
  but_prv = but_cur;
  but_cur = 0;
  
  // BUT_0 is shared with a LED, so we temporarily steal the pin, but set it back
  uint8_t restore0=digitalRead(BUT_0_PIN);
  pinMode(BUT_0_PIN, INPUT_PULLUP);
    if( digitalRead(BUT_0_PIN)==0 ) but_cur |= BUT_0; // Low-active
  pinMode(BUT_0_PIN, OUTPUT);
  digitalWrite(BUT_0_PIN,restore0);

  // BUT_1 is shared with a LED, so we temporarily steal the pin, but set it back
  uint8_t restore1=digitalRead(BUT_1_PIN);
  pinMode(BUT_1_PIN, INPUT_PULLUP);
    if( digitalRead(BUT_1_PIN)==0 ) but_cur |= BUT_1; // Low-active
  pinMode(BUT_1_PIN, OUTPUT);
  digitalWrite(BUT_1_PIN,restore1);
}


void but_init() {
  // The buttons pins are shared with the LEDs', so we set the input mode during readout only
  but_scan();
  but_scan();
}


uint8_t but_wentdown(uint8_t buts) {
  return (but_prv^but_cur) & but_cur & buts;
}


// === mode ===========================================


#define MODE_ALL       0
#define MODE_HALF      1
#define MODE_HALF2     2
#define MODE_BIN       3
#define MODE_WALK      4
#define MODE_WALK2     5
#define MODE_WALK3     6
#define MODE_RND       7
#define MODE_RNDHI     8
#define MODE_COUNT     9


// Which animation mode, wich substate, and how long for one animation step
uint8_t mode = MODE_RNDHI;
uint8_t state = 0;
uint8_t wait100ms = 8;


#if 0 // 1 for Serial support
  #warning Compiled with serial support
  const char * mode_names[MODE_COUNT]={"all","half","half2","bin","walk","walk2","walk3","rnd","rndhi"};
  void print_mode() {
    Serial.print("mode="); Serial.print(mode); Serial.print("="); Serial.print(mode_names[mode]);
    Serial.print("  wait100ms="); Serial.println(wait100ms);
  }
  void print_init() {
    Serial.begin(115200);
    Serial.println("\n\n");
    Serial.println("Welcome to multiblink");
  }
#else
  #warning Compiled without serial support
  #define print_mode() (void)0
  #define print_init() (void)0
#endif


const uint8_t popcount[32]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5};


// === main ====================================================


uint32_t last_step;
void setup() {
  print_init();
  led_init();
  last_step = millis();
  print_mode();
}


void loop() {
  
  but_scan();
  delay(10); // debounce
  if( but_wentdown(BUT_0) ) {
    wait100ms = wait100ms*2;
    if( wait100ms>64 ) wait100ms=1;
    print_mode();
  }
  if( but_wentdown(BUT_1) ) {
    mode = (mode+1) % MODE_COUNT;
    print_mode();
  }
    
  if( millis()-last_step > 100*wait100ms ) {
    // Next animation step  
    static uint8_t mask;
    uint8_t rev;
    
    switch( mode ) {
      
    case MODE_ALL:
      state = (state+1)%2; // Next step, but also clip for current mode
      mask = LED_ALL;
      rev = state;
      led_set( rev ? ~mask : mask );
      break;
      
    case MODE_HALF:
      state = (state+1)%2;
      mask = LED_1+LED_3;
      rev = state;
      led_set( rev ? ~mask : mask );
      break;
      
    case MODE_HALF2:
      state = (state+1)%2;
      mask = LED_3+LED_4;
      rev = state;
      led_set( rev ? ~mask : mask );
      break;
      
    case MODE_BIN:
      state = (state+1)%32;
      mask = state;
      led_set( mask );
      break;
    
    case MODE_WALK:
      state = (state+1)%5;
      mask = 1<<state;
      led_set( mask );
      break;
    
    case MODE_WALK2:
      state = (state+1)%5;
      mask = 1<<state;
      mask |= 1<<((state+1)%5);
      led_set( mask );
      break;
    
    case MODE_WALK3:
      state = (state+1)%5;
      mask = 1<<state;
      mask |= 1<<((state+1)%5);
      mask |= 1<<((state+2)%5);
      led_set( mask );
      break;
    
    case MODE_RND:
      state = random(0,32);
      if( state==mask ) state = (state+1)%32; // no duplicates
      mask = state;
      led_set( mask );
      break;
  
    case MODE_RNDHI:
      state = random(0,32);
      while( popcount[state]<2 || state==mask ) state = (state+1)%32;
      mask = state;
      led_set( mask );
      break;
  
    }
    last_step = millis();
  }
  
}
