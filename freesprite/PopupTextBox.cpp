#include "PopupTextBox.h"
#include "FontRenderer.h"
#include "UIButton.h"

PopupTextBox::PopupTextBox(std::string tt, std::string tx, std::string defaultValue, int textFieldWidth)
{
	wxHeight = 240;

    UIButton* nbutton = actionButton(TL("vsp.cmn.confirm"));
    nbutton->setCallbackListener(0, this);

    UIButton* nbutton2 = actionButton(TL("vsp.cmn.cancel"));
    nbutton2->setCallbackListener(1, this);

    tbox = new UITextField();
    tbox->position = XY{ 20, 80 };
    tbox->wxWidth = textFieldWidth;
    tbox->setCallbackListener(0, this);
    tbox->setText(defaultValue);
    wxsManager.addDrawable(tbox);

    wxsManager.forceFocusOn(tbox);

    makeTitleAndDesc(tt, tx);
}