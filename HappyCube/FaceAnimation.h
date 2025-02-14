/**
 * Face Animation Module
 * 
 * This module defines a simple structure for animating a face on the display.
 * It tracks position, speed, and size, allowing smooth movement across frames.
 * 
 * Author: Lukas Bochnick
 */

#ifndef FACE_ANIMATION_H
#define FACE_ANIMATION_H

#include <Arduino.h>

/**
 * Structure representing an animated face.
 */
struct FaceAnimation {
    int16_t x;       // Horizontal position (pixels)
    int16_t y;       // Vertical position (pixels)
    int8_t dx;       // Speed in x-direction (pixels per update)
    int8_t dy;       // Speed in y-direction (pixels per update)
    uint8_t faceSize; // Size of the face (symbolic, not directly used here)

    /**
     * Constructor to initialize face animation properties.
     * 
     * @param startX Initial x position
     * @param startY Initial y position
     * @param speedX Speed in x-direction
     * @param speedY Speed in y-direction
     * @param size Face size (symbolic)
     */
    FaceAnimation(int16_t startX, int16_t startY, int8_t speedX, int8_t speedY, uint8_t size)
        : x(startX), y(startY), dx(speedX), dy(speedY), faceSize(size) {}
};

/**
 * Draw the animated face on the display.
 * 
 * @param fa Reference to the FaceAnimation object
 */
void drawFace(const FaceAnimation &fa);

/**
 * Update the face's position based on its speed.
 * 
 * @param fa Reference to the FaceAnimation object
 */
void updateFacePosition(FaceAnimation &fa);

#endif
