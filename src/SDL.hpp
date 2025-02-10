#ifndef __SDL_SYSTEMS__
#define __SDL_SYSTEMS__

struct SDL_Color;
struct SDL_Renderer;


class SDL
{
    private:
        static SDL_Renderer* renderer;
        static SDL_Window* window;

    public:
        static bool Init (const char* windowTitle,
                          int width,
                          int height);

        static void Shutdown ();

        static void ClearWindow ();
        static void RefreshWindow ();
        static SDL_Renderer* Renderer ();
        static void SetClearColor (SDL_Color color);
        static SDL_Window* Window ();
};

#endif