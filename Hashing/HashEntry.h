#ifndef HASHENTRY_H
#define HASHENTRY_H
template <class T> class HashEntry {
    public:
        T element;
        bool isActive;
        HashEntry () {
            isActive=false;
        }
        HashEntry (T e, bool i) {
            element=e;
            isActive=i;
        }
}; 
#endif /* HASHENTRY_H */

