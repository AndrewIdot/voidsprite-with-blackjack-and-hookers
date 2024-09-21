#pragma once
#include "BaseBrush.h"
#include "globals.h"
#include "EventCallbackListener.h"

class ToolText :
    public BaseBrush, EventCallbackListener
{
public:
    TTF_Font* font = NULL;
    std::string text = "";
    int textSize = 16;
    SDL_Surface* textSurface = NULL;
    SDL_Texture* cachedTextTexture = NULL;

    std::string getName() override { return "Text"; }
    std::string getIconPath() override { return VOIDSPRITE_ASSETS_PATH "assets/tool_text.png"; }
    bool overrideRightClick() override { return true; }
    void clickPress(MainEditor* editor, XY pos) override;
    void rightClickPress(MainEditor* editor, XY pos) override;
    void renderOnCanvas(XY canvasDrawPoint, int scale);

    void eventPopupClosed(int evt_id, BasePopup* target) override;

    void renderText();
};

