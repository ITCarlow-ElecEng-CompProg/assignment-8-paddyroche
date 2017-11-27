/**
Patrick Roche
Exercise 8
Operational Amplifier Circuits */

/** Preprocessor directives */
#include <iostream>
#include <iomanip>
/** allows getchar() */
#include <cstdio>
/** allows system(cls) */
#include <windows.h>
#include <math.h>

/** Enables cout, cin and endl */
using namespace std;

/**< Functions being used */
char displayMenu(void);
void invert (void);
void noninvert (void);
void inverting(double *pav1, double rf, double rin, double *pvout1, double vin);
void noninverting(double *pav1, double r2, double r1, double *pvout1, double vin);


/** Main function */
int main(void)
{
    /** declare variables */
    char choice;
    /** do while loop to get the user to select which operation they want to use */
    do
    {
        choice = displayMenu();
        /** switch case to select which sub-functions operations to carry out */
        switch (choice)
        {
            case 'a':       invert();
                            break;

            case 'b':       noninvert();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
    }
}
    while (choice != 'q' );

    return 0;
}

/** function header */
char displayMenu(void)
{
    /** declaring variable type char */
    char choice;
    /** turns previous screen off */
    system("cls");
    /** user enters which command they want to use */
    cout <<"Operational Amplifier Circuits" ;
    cout <<"\n\nPress 'a' for an inverting amplifier ...";
    cout <<"\nPress 'b' for a non-inverting amplifier ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";
    /** gets rid of bugs */
    fflush(stdin);
    choice = getchar();
    return choice;
}

void invert ()
{
    /** turns previous screen off */
    system("cls");

    double vcc = -1, vee = 1, vin, rin = 0, rf = 0, av, vout;

    /**< These are pointers to the doubles 'av and vout' */
    double *pav, *pvout;

    /**< pointers 'pav and pvout are initialised as pointing to the memory address of 'av and vout' */
    pav = &av;
    pvout = &vout;
    /** heading */
    cout << "Inverting Amplifier Circuit\n\n" ;

    /** Ensuring positive values for rin in a while loop */
    while (rin <= 0)
    {
        cout << "\nRin :\t";
        cin >> rin;
    }
    /** Ensuring positive values for rf in a while loop */
    while (rf <= 0)
    {
        cout << "\nRf :\t";
        cin >> rf;
    }
    /** Ensuring positive values for vcc in a while loop */
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    /** Ensuring negative values for vee in a while loop */
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    /** Reading in values for vin */
    cout << "\nVin :\t";
    cin >> vin;

    /** calling function inverting */
    inverting (pav, rf, rin, pvout, vin);
    /** displaying values for gain and vout */
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout;

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout >= vee || vout <= vcc)
    {
        if(vin <= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }
    /** displayed on main console instructions for user to get back to main screen */
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();
    /** returns something back to main functon */
    return ;
}
/** Sub function to calculate gain and vout */
void inverting(double *pav1, double rf, double rin, double *pvout1, double vin)
{
    /**< Changes the value stored in pointer 'pav1's' memory to the value for the 'av' (gain) */
    *pav1 = -(rf/rin);
    /**< Changes the value stored in pointer 'pav1's' memory to the value for the 'av' (gain) */
    *pvout1 = *pav1 * vin;
    /** returning no value but have assigned a value in each pointers address */
    return ;
}
/** sub function for non inverting amplifier */
void noninvert ()
{
    /** turns previous screen off */
    system("cls");
    /** declare variables */
    double vcc = -1, vee = 1, vin, r1 = 0, r2 = 0, av, vout;

     /**< These are pointers to the doubles 'av and vout' */
    double *pav, *pvout;

    /**< pointers 'pav and pvout are initialised as pointing to the memory address of 'av and vout' */
    pav = &av;
    pvout = &vout;

    /** display heading */
    cout << "Non - Inverting Amplifier Circuit\n\n" ;

    /** Ensuring positive values for r1 in a while loop */
    while (r1 <= 0)
    {
        cout << "\nR1 :\t";
        cin >> r1;
    }
    /** Ensuring positive values for r2 in a while loop */
    while (r2 <= 0)
    {
        cout << "\nR2 :\t";
        cin >> r2;
    }
    /** Ensuring positive values for vcc in a while loop */
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    /** Ensuring neg values for vee in a while loop */
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    /** read oin values for vin */
    cout << "\nVin :\t";
    cin >> vin;

    /** calling subfunction */
    noninverting (pav, r2, r1, pvout, vin);

    /** displaying values for gain and vout */
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout ;

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout <= vee || vout >= vcc)
    {
        if(vin >= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }

    /** displayed on main console instructions for user to get back to main screen */
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();
    /** returns something back to main functon */
    return ;
}
/** sub function to calculate gain and vout for non inverting amplifier */
void noninverting(double *pav1, double r2, double r1, double *pvout1, double vin)
{
    /**< Changes the value stored in pointer 'pav1's' memory to the value for the 'av' (gain) */
    *pav1 = 1 + (r2 / r1);
    /**< Changes the value stored in pointer 'pav1's' memory to the value for the 'av' (gain) */
    *pvout1 = *pav1 * vin;
    /** returning no value but have assigned a value in each pointers address */
    return ;
}
