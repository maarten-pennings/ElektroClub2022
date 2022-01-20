# ElektroClub2022
End-of-year project (2022) for the ElektroClub


## Minutes of the project

Sorry (double) in Dutch and in [Word](ElektroClub2022-plan.docx) (and [pdf](ElektroClub2022-plan.pdf))


## Checking the CD4060 behavior

The internals (first for flipflops not bound, and also number 11 is missing...)

![4060 internals](CD4060-internals.png)

and the time [calculation](timing.xlsx).


## Schematics

The schematics is based on one from [buildcircuit](https://www.buildcircuit.com/diy-kit-8-happy-birthday-led-flashing-diy-kit-using-cd4060-and-music-chip/).
We have 5 groups, not three. And we added some capacitors.
We were initially puzzled by the diodes, we now believe the form a wired to, resetting when all groups have their basis at +5V,
that is when the CD4060 reaches 31. This means all LEDs are of, and this triggers a reset.

The final [schematic](schematic.pdf).


## PCB cutout

The design of the big "2022" digits is made in [Visio](outline.vsdx).

Converted to [DXF outline](outline.dxf) and [png letters](letters.png).

The resulting PCB:

![PCB](pcb.png).

(end)
