#include "ToolMeasure.h"
#include "mathops.h"
#include "FontRenderer.h"
#include "TooltipsLayer.h"

void ToolMeasure::clickPress(MainEditor* editor, XY pos)
{
	heldDown = true;
	lastMousePos = pos;
	startPos = pos;
	clickTimer.start();
}

void ToolMeasure::renderOnCanvas(XY canvasDrawPoint, int scale)
{
	if (heldDown) {
		drawPixelRect(startPos, lastMouseMotionPos, canvasDrawPoint, scale);
		XY pointFrom = XY{ ixmin(startPos.x, lastMouseMotionPos.x), ixmin(startPos.y, lastMouseMotionPos.y) };
		XY pointTo = XY{ ixmax(startPos.x, lastMouseMotionPos.x), ixmax(startPos.y, lastMouseMotionPos.y) };

		g_ttp->addTooltip(Tooltip{
			canvasDrawPoint.x + lastMousePos.x * scale + 25, canvasDrawPoint.y + lastMousePos.y * scale,
			std::format("{}px x {}px", pointTo.x - pointFrom.x + 1, pointTo.y - pointFrom.y + 1),
			{0xff,0xff,0xff,0xff},
			clickTimer.percentElapsedTime(200)
		});
	}

	SDL_SetRenderDrawColor(g_rd, 0xff, 0xff, 0xff, 0x30);
	drawLocalPoint(canvasDrawPoint, lastMouseMotionPos, scale);
	SDL_SetRenderDrawColor(g_rd, 0, 0, 0, 0x80);
	drawPointOutline(canvasDrawPoint, lastMouseMotionPos, scale);
	
}
