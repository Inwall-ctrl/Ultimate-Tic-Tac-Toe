#include<iostream>
#include "raylib.h"
#include<vector>
using namespace std;

#ifndef ULTIMATETTT_BUTTON_H
#define ULTIMATETTT_BUTTON_H

class Button {
private:
    Rectangle bound{};
    Texture2D background_image{};
    bool click; // Flag to indicate whether the button has been clicked
    bool active;
public:
    int Id;

    explicit Button(Rectangle _bounds, int id);
    bool IsClicked() const;
    void SetActive(bool isActive);
    void SetImage(Texture2D image);

    void Update();
    void Draw();
};

#endif //ULTIMATETTT_BUTTON_H
