#include "playerInfo.h"
#include "numericEntryPanel.h"

#include "gui/gui2_panel.h"
#include "gui/gui2_label.h"
#include "gui/gui2_button.h"
#include "gui/gui2_autolayout.h"

GuiControlNumericEntryPanel::GuiControlNumericEntryPanel(GuiContainer* owner, string id, string title)
: GuiElement(owner, id)
{
    setSize(GuiElement::GuiSizeMax, GuiElement::GuiSizeMax);
    
    box = new GuiPanel(this, id + "_BOX");
    box->setPosition(0, 0, ACenter);
    GuiAutoLayout* layout = new GuiAutoLayout(box, id + "_LAYOUT", GuiAutoLayout::LayoutVerticalTopToBottom);
    layout->setSize(GuiElement::GuiSizeMax, GuiElement::GuiSizeMax);
    title_label = new GuiLabel(layout, id + "_LABEL", title, 50);
    title_label->setSize(GuiElement::GuiSizeMax, 80);
    code_label = new GuiLabel(layout, id + "_CODE_LABEL", "", 30);
    code_label->addBackground()->setSize(GuiElement::GuiSizeMax, 50);
    
    code_entry = new GuiElement(layout, id + "_ENTRY_ELEMENT");
    code_entry->setSize(250, 320);
    
    prompt_label = new GuiLabel(code_entry, id + "_ENTRY_LABEL", "", 30);
    prompt_label->addBackground()->setSize(GuiElement::GuiSizeMax, 50);
    code_entry_label = new GuiLabel(code_entry, id + "_ENTRY_LABEL", "", 30);
    code_entry_label->addBackground()->setPosition(0, 50, ATopLeft)->setSize(GuiElement::GuiSizeMax, 50);
    (new GuiButton(code_entry, id + "_BUTTON_7", "7", [this]() {code_entry_label->setText(code_entry_label->getText() + "7");}))->setSize(50, 50)->setPosition(50, 100, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_8", "8", [this]() {code_entry_label->setText(code_entry_label->getText() + "8");}))->setSize(50, 50)->setPosition(100, 100, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_9", "9", [this]() {code_entry_label->setText(code_entry_label->getText() + "9");}))->setSize(50, 50)->setPosition(150, 100, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_4", "4", [this]() {code_entry_label->setText(code_entry_label->getText() + "4");}))->setSize(50, 50)->setPosition(50, 150, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_5", "5", [this]() {code_entry_label->setText(code_entry_label->getText() + "5");}))->setSize(50, 50)->setPosition(100, 150, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_6", "6", [this]() {code_entry_label->setText(code_entry_label->getText() + "6");}))->setSize(50, 50)->setPosition(150, 150, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_1", "1", [this]() {code_entry_label->setText(code_entry_label->getText() + "1");}))->setSize(50, 50)->setPosition(50, 200, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_2", "2", [this]() {code_entry_label->setText(code_entry_label->getText() + "2");}))->setSize(50, 50)->setPosition(100, 200, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_3", "3", [this]() {code_entry_label->setText(code_entry_label->getText() + "3");}))->setSize(50, 50)->setPosition(150, 200, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_Clr", "Clr", [this]() {
        code_entry_label->setText("");
        if (clear_func)
        {
            func_t f = clear_func;
            f(0);
        }
    }))->setSize(50, 50)->setPosition(50, 250, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_0", "0", [this]() {code_entry_label->setText(code_entry_label->getText() + "0");}))->setSize(50, 50)->setPosition(100, 250, ATopLeft);
    (new GuiButton(code_entry, id + "_BUTTON_OK", "OK", [this]() {
        if (enter_func)
        {
            func_t f = enter_func;
            f(code_entry_label->getText().toInt());
        }
    }))->setSize(50, 50)->setPosition(150, 250, ATopLeft);
    code_entry->setVisible(true);
}

void GuiControlNumericEntryPanel::setTitle(string prompt) {
    title_label->setText(prompt);
}

void GuiControlNumericEntryPanel::setPrompt(string prompt) {
    prompt_label->setText(prompt);
}

GuiControlNumericEntryPanel* GuiControlNumericEntryPanel::enterCallback(func_t func)
{
    this->enter_func = func;
    return this;
}

GuiControlNumericEntryPanel* GuiControlNumericEntryPanel::clearCallback(func_t func)
{
    this->clear_func = func;
    return this;
}

void GuiControlNumericEntryPanel::onDraw(sf::RenderTarget& window)
{
   
    if (code_entry->isVisible())
        box->setSize(600, code_entry->getPositionOffset().y + code_entry->getSize().y);
    else if (code_label->isVisible())
        box->setSize(600, code_label->getPositionOffset().y + code_label->getSize().y);
    else
        box->setSize(600, 80);
}
