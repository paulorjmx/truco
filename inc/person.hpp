#ifndef PERSON_HPP
    #define PERSON_HPP
        #include <iostream>

        using namespace std;
        class Person
        {
            protected:
                string name;

            public:
                virtual void set_name(string name) = 0;
                virtual string get_name() = 0;
        };
#endif
