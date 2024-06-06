#include "raylib.h"
#include "button.h"

Button::Button(Rectangle _bounds, int id) {
    Id = id;
    bound = _bounds;
    click = false;
    active = true;
}

void Button::SetImage(Texture2D image) {
    background_image = image;
}

bool Button::IsClicked() const {
    return click;
}

void Button::SetActive(bool isActive) {
    active = isActive;
}

void Button::Update() {
    Vector2 mousePosition = GetMousePosition();

    if (active && CheckCollisionPointRec(mousePosition, bound)) {
        click = true;
    } else {
        click = false;
    }
}

void Button::Draw() {
    Color tintColor = active ? WHITE : GRAY;
    DrawRectangleRec(bound, tintColor);
    DrawTexture(background_image, static_cast<int>(bound.x), static_cast<int>(bound.y), tintColor);
}
