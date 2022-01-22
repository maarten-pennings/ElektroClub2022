# Stand model

I modeled (in [Fusion 360](https://www.autodesk.eu/products/fusion-360) how the PCB could stand-up using feet made as part of the PCB.

## Idea outline

The key idea is to use slots to join two planes.

The maximum PCB size of the "makers deal" at [JLCPCB](https://jlcpcb.com) is 100 mm by 100 mm (actually 4 in by 4 in).
The two feet are made of a 15 mm strip at the bottom (full length 0f 100 mm), 
so the main part is for the actual PCB: 83 mm by 100 mm. Note that 15 plus 83 is 98, we have 2 for separation slits.

I decided that each foot has _two_ slots: one straight and one at 75 degrees so that you have two options for the stand: 
straight and slanted.

![concept](concept.png)

## Dimensions

The PCB thickness is 1.6 mm, to have a tight fit I made the slots 1.5 mm.

![design](Dimensions.png)


## Artist impression

![slanted](feet-slanted.png)

![straight](feet-straight.png)

## Next step

Next step is to create the actual "board outline" for the PCB.
This includes gaps for the digits. See [pcboutline](../pcboutline).

(end)
