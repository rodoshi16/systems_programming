***Buffers in networking***

Buffers are used to temporarily store data as it travels between sender and receiver. Buffers exist in:

- user space: memory space where the application runs
- kernel space: managed by the operating system and acts as a middleman that handles actual data transmission. 

*Data flow*:

Sender Side:
User Space (your app) → User Buffer → send() → Kernel Space → Kernel Send Buffer → Network

Receiver Side:
Network → Kernel Receive Buffer → recv() → Kernel Space → User Buffer → User Space (your app)





