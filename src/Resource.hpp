#ifndef __RESOURCE__
#define __RESOURCE__

class Resource
{
    protected:
        const char* filePath = "";
        bool exists = false;

        virtual void Dispose ();

    public:
        Resource (const char* filePath);
        ~Resource ();

        virtual bool IsValid () = 0;
};

#endif
