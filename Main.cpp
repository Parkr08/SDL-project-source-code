#include "Main.h"

int main(int argc, char* argv[]) {
    // Initialize SDL3's video subsystem.
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    // Create a window.
    // In SDL3, SDL_CreateWindow takes 4 parameters: title, width, height, flags.
    SDL_Window* window = SDL_CreateWindow("Fullscreen Blue Rectangle", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    // Retrieve the current display mode for that display.
    const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(1);
    if (!mode) {
        cerr << "SDL_GetCurrentDisplayMode Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    cout << "Display resolution: " << mode->w << " x " << mode->h << "\n";

    // Set the window's fullscreen mode using the current display mode.
    // This will change our window so that it exactly covers the display.
    if (!SDL_SetWindowSize(window, mode->w, mode->h)) {
        cerr << "SDL_SetWindowFullscreenMode Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Center window to the screen
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    // Bring window to the front (sometimes output panel display in front)
    SDL_SetWindowAlwaysOnTop(window, true);

    // Create a renderer for drawing.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Calculate the centered position for our 400x300 blue rectangle.
    // The current mode gives the resolution of the fullscreen display.
    int rectW = 400;
    int rectH = 300;
    int rectX = (mode->w - rectW) / 2;
    int rectY = (mode->h - rectH) / 2;
    SDL_FRect rect = { rectX, rectY, rectW, rectH };

    bool running = true;
    SDL_Event event;

    // Main loop: handle events and render.
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Clear the screen with a black background.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set the draw color to blue (RGBA: 0, 0, 255, 255).
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        // Draw the filled blue rectangle.
        SDL_RenderFillRect(renderer, &rect);

        // Present the rendered frame.
        SDL_RenderPresent(renderer);
    }

    // Cleanup resources.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


