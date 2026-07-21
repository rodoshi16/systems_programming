***Malloc***

As seen in the code from dynamic_model.c, we know that the reason we use malloc is to allocate memory on the heap instead of the stack. 

If we call a function where we are declaring a variable on the stack but we store that address in a pointer, once the function returns, the address can be reused for a different purpose. 

```
void *malloc(size_t size)
```
The memory on malloc remains accessible until the programmer frees it. 

Returns a void pointer 