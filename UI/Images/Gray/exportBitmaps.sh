#!/bin/bash

# Shell script to export the quadrant bitmaps from the Inkscape SVG files.
# Usage:
#	Open Inkscape and hide the layer you don't want exported, show the one you do.
#	To export as the lit quadrant bitmaps, enter "./exportBitmaps.sh lit"
#	Enter "./exportBitmaps.sh" for the regular quadrants.

#inkscape -i area-id -eFilename.png filename.svg


if [ $1 = "lit" ]
then
	echo "Exporting lit quadrants"
	inkscape -i TopLeft -eSimonTopLeftLit.png Simon.svg
	inkscape -i TopRight -eSimonTopRightLit.png Simon.svg 
	inkscape -i BottomLeft -eSimonBottomLeftLit.png Simon.svg 
	inkscape -i BottomRight -eSimonBottomRightLit.png Simon.svg
else
	echo "Exporting unlit quadrants"
	inkscape -i TopLeft -eSimonTopLeft.png Simon.svg
	inkscape -i TopRight -eSimonTopRight.png Simon.svg 
	inkscape -i BottomLeft -eSimonBottomLeft.png Simon.svg 
	inkscape -i BottomRight -eSimonBottomRight.png Simon.svg
fi
