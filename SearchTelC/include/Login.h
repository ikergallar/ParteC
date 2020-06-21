#ifndef LOGIN_H
#define LOGIN_H


class login
{
    char *nombre;
    char *pass;
    public:
        login();
        login(char *n,char *p);
        void iniciarSesion();
        virtual ~login();


};

#endif // LOGIN_H
