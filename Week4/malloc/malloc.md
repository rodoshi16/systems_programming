***Malloc***

As seen in the code from dynamic_model.c, we know that the reason we use malloc is to allocate memory on the heap instead of the stack. 

If we call a function where we are declaring a variable on the stack but we store that address in a pointer, once the function returns, the address can be reused for a different purpose. 

```
void *malloc(size_t size)
```
The memory on malloc remains accessible until the programmer frees it. 

Returns a void pointer 


```

int main (){
    float *rainfall = NULL: 
    //allocate space for a single floating point number and assign its location to the pointer rainfall
    rainfall = malloc(sizeof(float)); 
    *rainfall = 42.6; 
    return 0; 

}

```

## Dynamic Memory Practice 2A

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    float *rainfall = NULL;

    // Allocate space for a single floating point number and assign its location to the pointer rainfall.
    rainfall = malloc(sizeof(float)); 

    *rainfall = 42.6;

    return 0;
}
```

---

## Dynamic Memory Practice 2B

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int allocated_amount;

    // Set the value of allocated_amount:
    allocated_amount = sizeof(float);

    return 0;
}
```

---

## Dynamic Memory Practice 2C

```c
int main(int argc, char **argv) {
    float *rainfall;
    float rain_today;

    // rainfall has been dynamically allocated space for a floating point number.
    // Both rainfall and rain_today have been initialized in hidden code.
    // Assign the amount in rain_today to the space rainfall points to.

    *rainfall = rain_today;

    return 0;
}
```

---

## Dynamic Memory Practice 2D

```c
int main(int argc, char **argv) {
    float total_rain;
    float *rainfall;

    // rainfall has been dynamically allocated space for a floating point number.
    // Both rainfall and total_rain have been initialized in hidden code.
    // Increase the amount currently stored in total_rain by the amount stored in
    // the space pointed to by rainfall.

    total_rain = total_rain + *rainfall;

    return 0;
}
```

---

## Dynamic Memory Practice 2E

```c
int main(int argc, char **argv) {
    float *rainfall;

    // rainfall has been dynamically allocated space for a floating point number and initialized in hidden code.
    // Add 7.6 to the amount currently stored in the space rainfall points to.

    *rainfall = *rainfall + 7.6;

    return 0;
}
```

---

## Dynamic Memory Practice 2F

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    float *monthly_rainfall = NULL;

    // Allocate space on the heap for an array of 12 floats and assign it to the pointer monthly_rainfall.

    monthly_rainfall = malloc(12 * sizeof(float));

    for (int i; i < 12; i++) {
        monthly_rainfall[i] = set_rain();
    }

    return 0;
}
```
