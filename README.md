# Semaphore Implementation in C++

A basic implementation of a **Semaphore in C++** using `mutex` and `condition_variable`.

This project demonstrates how semaphores can be used for **thread synchronization** and to control access to a critical section.

## Concepts Covered

- Semaphore
- Binary Semaphore
- Thread Synchronization
- Critical Section
- Mutex
- Condition Variable
- `unique_lock`
- `wait()` and `signal()` operations
- C++ Multithreading

## How It Works

The semaphore maintains an integer `count` representing the number of available resources.

### `wait()`

The `wait()` operation checks whether a resource is available.

```cpp
while (count <= 0) {
    cv.wait(lock);
}

count--;
```

If `count` is zero, the thread waits until a resource becomes available.

### `signal()`

The `signal()` operation releases a resource.

```cpp
count++;
cv.notify_one();
```

It increases the semaphore count and wakes one waiting thread.

## Implementation

The semaphore uses:

- `std::mutex` to protect the shared `count`
- `std::unique_lock` to safely acquire and release the mutex
- `std::condition_variable` to block and wake threads

For this implementation:

```cpp
Semaphore sem(1);
```

creates a **binary semaphore**, allowing only one thread to enter the critical section at a time.

## Example

Three threads are created:

```cpp
thread t1(fun, 1);
thread t2(fun, 2);
thread t3(fun, 3);
```

Although all three threads can execute concurrently, the semaphore ensures that only one thread enters the critical section at a time.

The execution order is not
