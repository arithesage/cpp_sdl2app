#ifndef __RESOURCE__
#define __RESOURCE__

class Resource
{
    protected:
        const char* filePath = "";
        bool exists = false;

        virtual void Dispose ();

    public:
        Resource ();
        Resource (const char* filePath);
        ~Resource ();

        virtual bool IsValid ();
};

#endif
