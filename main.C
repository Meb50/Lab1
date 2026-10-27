#include <stdio.h> 
#define MAX 100 

struct cg { // structure to hold x and y coordinates and mass 
            float x, y, mass; 
        }masses[MAX]; // sets the indexes in the array to each mass provided.

int readin(void)
    { 
        /* Write this function to read in the data into the array masses note that this function should return the number of masses read in from the file */ 
        int n;
        printf("Enter the number of masses: \n"); 
        scanf("%d", &n); //reads the input as an integer and assigns it to the address of n
        printf("Enter the x, y coordinates and mass for each mass: \n"); 
        if(n > MAX || n == 0)
        {
            return 0; //if the input is greater than the max number of masses OR there are no masses, return FALSE.
        }
        for (int i = 0; i < n; i++) 
        {
            scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass); // for the number of inputted massses, inputs the x,y coordinates and mass of each of the masses into the array
        }
        return n; //returns the number of masses, since it's > 0 it returns as TRUE.
    
    }

void computecg(int n_masses) 
    { 
        /* Write this function to compute the C of G and print the result */
        float sum_of_xmass = 0;
        float sum_of_ymass = 0; 
        float sum_of_mass = 0; //SETS FLOAT VARIABLES.
        float cg_x, cg_y;
        for (int i = 0; i < n_masses; i++) 
        {
            sum_of_xmass += masses[i].x * masses[i].mass; //sum of the x coords multiplied by the masses at each mass position in the array
            sum_of_ymass += masses[i].y * masses[i].mass; //sum of the y coords multiplied by the masses at each mass position in the array
            sum_of_mass += masses[i].mass; //sum of the masses

            cg_x = sum_of_xmass / sum_of_mass; //calculates the x coords of the centre of gravity
            cg_y = sum_of_ymass / sum_of_mass; //calculates the y coords of the centre of gravity
            
        }
        printf("The center of gravity is at (%f, %f)\n", cg_x, cg_y);
        if(sum_of_mass == 0)
        {
            return; //if the sum of the mass is 0, return FALSE.
        }
    } 

int main(void)
{
    int number;
    if ((number = readin()) > 0) //if the number of masses is greater than 0, function computecg is performed
    {
        computecg(number);
    }
    else
    {
        return 0;
    }
}