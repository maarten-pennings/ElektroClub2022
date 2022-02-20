# ElektroClub2022

End-of-year project (2022) for the ElektroClub.


## Introduction

In my village I'm volunteer for at an "ElectroClub" for children 8 to 12 years.
At the end of the (school) year we try to have a master piece for them, to remember the club.
In 2022 we wanted the year digits with flashing numbers; this is actually a copy of an old project:

![front](2014-front.jpg) ![back](2014-back.jpg) ![pcb](2014-pcb.jpg)

What we remembered from 2014 is that creating the wooden panels, soldering all the LED wires, 
gluing all wires in place was too time consuming.
This year we will try a variation: designing the PCB using [EasyEDA](https://easyeda.com)
and manufacturing it via [JLCPCB](https://jlcpcb.com/). 
The biggest challenge is to get a nice rendering of the big digits 2022.

We have minutes of the project in [Word](ElektroClub2022-plan.docx) or [pdf](ElektroClub2022-plan.pdf) - sorry they are in Dutch.


## Schematics

The 2014 schematics were lost in time, so we needed some googling.
The heart of the circuit is the [4060 binary counter](https://www.ti.com/lit/ds/symlink/cd4060b.pdf):

![4060 internals](CD4060-internals.png)

The schematics is based on one from [buildcircuit](https://www.buildcircuit.com/diy-kit-8-happy-birthday-led-flashing-diy-kit-using-cd4060-and-music-chip/).
However, we have 5 groups of LEDs, not three. And we added some capacitors for stabilization.

We will use the outputs to flash the LEDs; here are some time [calculations](timing.xlsx).

We were initially puzzled by the diodes, we now believe they form a "wired OR", 
resetting the CD4060 when all three (five) transistor basis are high.
This is when the CD4060 reaches 0b...111 (0b...11111). 
In that situation all LEDs are off. 

In other words at the same moment all LEDs are switched off, 
the CD4060 is reset and outputs 0b...0000 and all LEDs are on.

Our final [schematic](schematic.pdf).


## Stand

I wanted the PCB to have small feet.
I made a [3D model](standmodel) to check the position of the slots.

![slots](standmodel/concept.png)![model](standmodel/feet-slanted.png)


## Board outline

A step that took quite some time was the design of the [board outline](pcboutline).
This includes the big "2022" digits, because I wanted to cut them out.
I made the design in Visio, because that can save to DXF, the format needed by the PCB tool.

![outline](pcboutline/outline.png)


## PCB

The resulting PCB as a render, front and back side.

![PCB](pcb.png)

![PCB backside](pcb-back.png)

The [gerber](Gerber_ElektroClub2022_pcb.zip) is also available.


## Order

I ordered 5 red, 10 green and 5 black at jlcpcb; pricing: €1.76, €4.41, €3.53 respectively 
plus €15.85 shipping. Total €25.55.

(end)
