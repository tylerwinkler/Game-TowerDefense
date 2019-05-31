#ifndef TOWERTOOLTIP_HPP
#define TOWERTOOLTIP_HPP

class TowerTooltip : public UIElement
{
public:
    TowerTooltip();

public:
    void show();
    void hide();

private:
    UIFrame frame;
    UIButton upgradeButton;
}; // UIElement

#endif // TOWERTOOLTIP_HPP
