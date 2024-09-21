#pragma once
#include "BaseBrush.h"
class Brush1x1ArcY :
    public BaseBrush
{
	std::string getName() override { return "1x1 Pixel (arc Y)"; }
	std::string getIconPath() override { return VOIDSPRITE_ASSETS_PATH "assets/brush_px1x1arcy.png"; }
	void clickPress(MainEditor* editor, XY pos) override;
	void clickDrag(MainEditor* editor, XY from, XY to) override;
	void clickRelease(MainEditor* editor, XY pos) override {}
	void renderOnCanvas(XY canvasDrawPoint, int scale) {
		SDL_SetRenderDrawColor(g_rd, 0xff, 0xff, 0xff, 0x30);
		drawLocalPoint(canvasDrawPoint, lastMouseMotionPos, scale);
		SDL_SetRenderDrawColor(g_rd, 0, 0, 0, 0x80);
		drawPointOutline(canvasDrawPoint, lastMouseMotionPos, scale);
	}
};

