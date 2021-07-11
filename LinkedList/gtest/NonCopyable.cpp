struct noncopyable
{
    int value;
    noncopyable() = default;
    noncopyable(const noncopyable& other) = delete;
        noncopyable& operator=(const noncopyable&) = delete;

};



