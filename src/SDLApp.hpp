#ifndef __SDL_APP__
#define __SDL_APP__


class SDLApp
{
    private:
        bool ready = false;
        bool running = false;        

        void quit ();

    public:
        SDLApp (const char* title, int width, int height);
        ~SDLApp ();

        bool IsReady ();
        bool IsRunning ();
        void Start ();

    protected:
        virtual void OnStart ();
        virtual void OnRender ();
        virtual void OnUpdate ();
        virtual void OnQuit ();
};

#endif