#ifndef NUMERIC_ENTRY_PANEL_H
#define NUMERIC_ENTRY_PANEL_H

#include "gui/gui2_element.h"
#include "spaceObjects/playerSpaceship.h"

class GuiPanel;
class GuiLabel;

class GuiControlNumericEntryPanel : public GuiElement
{
private:
    GuiPanel* box;
    GuiLabel* title_label;
    GuiLabel* code_label;
    GuiElement* code_entry;
    GuiLabel* prompt_label;
    GuiLabel* code_entry_label;
    int code_entry_position;
    
    bool has_position[max_crew_positions];
public:
    typedef std::function<void(int number)> func_t;

    GuiControlNumericEntryPanel(GuiContainer* owner, string id, string title);

    virtual void onDraw(sf::RenderTarget& window);
    
    void enablePosition(ECrewPosition position) { has_position[position] = true; }

    void setTitle(string prompt);
    void setPrompt(string prompt);

    GuiControlNumericEntryPanel* enterCallback(func_t func);
    GuiControlNumericEntryPanel* clearCallback(func_t func);

protected:
    func_t enter_func;
    func_t clear_func;
};

#endif//NUMERIC_ENTRY_PANEL_H
