#ifndef __RESOURCE__
#define __RESOURCE__

class Resource
{
    protected:
        const char* filePath = "";

        virtual void Dispose ();

    public:
        Resource (const char* filePath);
        ~Resource ();

        virtual bool IsValid () = 0;
};

#endif
