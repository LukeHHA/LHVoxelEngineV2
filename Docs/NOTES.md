# Notes

Not important just to keep info that may be relevent as I think of it and typically quickly forget.

## OpenGl

- `ALPHA` channel is deprecated on macOS but can be replaced with `GL_RED` or `GL_RG`
- `Z+` Axis runs throught the screen towards you so to move the camera forward it must go along the +Z axis

## LHCraft

- change the debug macros to be `ifdef` based on the value define in the `cmakeConfig.h`
- Look back at camera and see if an interface is a better idea as a create function based on an enum
  identifying the camera type would be nice.
