# ElektroClub2022
End-of-year project (2022) for the ElektroClub


## Minutes of the project

Sorry (double) in Dutch and in [Word](ElektroClub2022-plan.docx) (and [pdf](ElektroClub2022-plan.pdf))


## Checking the CD4060 behavior

The internals (first four flipflops are not bound out, and also number 11 is missing...)

![4060 internals](CD4060-internals.png)

and the time [calculation](timing.xlsx).


## Schematics

The schematics is based on one from [buildcircuit](https://www.buildcircuit.com/diy-kit-8-happy-birthday-led-flashing-diy-kit-using-cd4060-and-music-chip/).
We have 5 groups of LEDs, not three. And we added some capacitors.
We were initially puzzled by the diodes, we now believe they form a "wired OR", resetting the CD4060 when all three (five) transistor basis are hi 
- when the CD4060 reaches 0b...111 (0b...11111). In that situation all LEDs are off. 

In other words at the same moment all LEDs are switched off, the CD4060 is reset and outputs 0b...0000 and all LEDs are on.

The final [schematic](schematic.pdf).


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

The resulting PCB.

![PCB](pcb.png)

![PCB backside](pcb-back.png)

(end)
