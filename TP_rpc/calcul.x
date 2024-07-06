struct data{
    unsigned int arg1;
    unsigned int arg2;
};
typedef struct data data;

struct response{
    unsigned int somme;
    int errno;
};

typedef struct response response;

program CALCUL{
    version VERSION_UN{
        void CALCUL_NULL(void) = 0;
        response CALCUL_ADDITION(data) = 1;
    }=1;
} = 0x20000001;

