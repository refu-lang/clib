/**
**      ==START OF REFU LICENSE==
**
** Copyright (c) 2011-2013, Karapetsas Eleftherios
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
**  1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
**  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the distribution.
**  3. Neither the name of the Original Author of Refu nor the names of its contributors may be used to endorse or promote products derived from
** 
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
** INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES;LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**      ==END OF REFU LICENSE==
**
**
** --Threads/mutex.h
** This header declares functions that operate on RF_Mutex
*/

#ifndef RF_MUTEX_H
#define RF_MUTEX_H

#include <Definitions/types.h> //for fixed size data types
#include <Definitions/imex.h> //for the import export macro
    #ifdef REFU_WIN32_VERSION
    #include <windows.h> //for HANDLE
    #else
    #include <pthread.h> //for pthread_mutex_t
    #endif
#include <Threads/mutex_decl.h> //for RF_Mutex
#include <Threads/mutex.h>

#ifdef __cplusplus
extern "C"
{///opening bracket for calling from C++
#endif

// Values for the flags parameters of a mutex creation//
// The mutex object will be locked at the beginning and owned by the calling thread
#define RF_MUTEX_LOCK_AT_INIT       0x01
// This is a hint and will only have an effect under Linux which use pthreads. The effect is as if calling PTHREAD_MUTEX_NORMAL attribute at creation which means that when you attempt to lock
// the mutex when owned by another thread, the calling thread is suspended forever.
#define RF_MUTEX_NORMAL             0x02
// This is a hint and will only have an effect under Linux which use pthreads. The effect is as if calling PTHREAD_MUTEX_RECURSIVE attribute at creation which means that when you attempt to lock
// the mutex when owned by another thread, the calling thread returns immediately with a success return code. The number of times the thread owning the mutex has locked it is recorded in the mutex.
// The owning thread must call rfThread_Unlcosk  the same number of times before the mutex returns to the unlocked state.
#define RF_MUTEX_RECURSIVE          0x04
// This is a hint and will only have an effect under Linux which use pthreads. The effect is as if calling PTHREAD_MUTEX_ERRORCHECK attribute at creation which means that when you attempt to lock
// the mutex when owned by another thread, the calling thread returns immediately with the error code RF_MUTEX_DEADLOCK
#define RF_MUTEX_ERRORCHECK         0x08

/**
 ** @memberof RF_Mutex
 ** @brief Allocates and returns a mutex object
 **
 ** For more infor look at @ref rfMutex_Init()
 **/
i_DECLIMEX_ RF_Mutex* rfMutex_Create(uint32_t flags);
/**
 ** @memberof RF_Mutex
 ** @brief Initializes a mutex object
 **
 ** @param m The mutex to initialize
 ** @param flags Hints for the creation of the mutex. Possible bitflag
 ** values/combinations:
 ** <ul><li><b>For all OS</b>: @c RF_MUTEX_LOCK_AT_INIT, means that the mutex
 ** object will be locked at the beginning and owned by the calling thread</li>
 ** <li><b>For Linux</b>:
 ** <ul><li>@c RF_MUTEX_NORMAL, The effect is as if calling 
 ** @c PTHREAD_MUTEX_NORMAL attribute at creation which means that when
 ** you attempt to lock the mutex when owned by another thread, the calling 
 ** thread is suspended forever</li>
 ** <li>@c RF_MUTEX_RECURSIVE, The effect is as if calling 
 ** @c PTHREAD_MUTEX_RECURSIVE attribute at creation which means that when
 ** you attempt to lock the mutex when owned by another thread, the calling
 ** thread returns immediately with a success return code. The number of times
 ** the thread owning the mutex has locked it is recorded in the mutex.
 ** The owning thread must call @ref rfMutex_Unlock the same number of times
 ** before the mutex returns to the unlocked state</li>
 ** <li>@c RF_MUTEX_ERRORCHECK, The effect is as if calling 
 ** @c PTHREAD_MUTEX_ERRORCHECK attribute at creation which means that when you
 ** attempt to lock the mutex when owned by another thread, the calling thread
 ** returns immediately with the error code RF_MUTEX_DEADLOCK</li></ul>
 ** </li></ul>
 ** @return Returns @c true in success and @c false in failure
 **/
i_DECLIMEX_ char rfMutex_Init(RF_Mutex* m, uint32_t flags);

/**
 ** @memberof RF_Mutex
 ** @brief Destroys the mutex and releases its memory
 **
 ** For more information refer to @ref rfMutex_Destroy()
 **/
i_DECLIMEX_ char rfMutex_Destroy(RF_Mutex* m);
/**
 ** @memberof RF_Mutex
 ** @brief Deinitializes the mutex
 **
 ** Make sure that it is not owned by any thread at the time you
 ** use this function
 ** @param m The mutex in question
 ** @return Returns @c true in succesfull destruction and false with
 ** error logging otherwise
 **/
i_DECLIMEX_ char rfMutex_Deinit(RF_Mutex* m);


/**
 ** @memberof RF_Mutex
 ** @brief Locks the mutex
 **
 ** If the mutex is already locked by another thread then this suspends the
 ** calling thread until the mutex is unlocked. Behaviour will only vary if
 ** The system is in Linux and using POSIX threads where the behaviour will
 ** depend on the flags given at mutex initialization.
 ** @param m The mutex in question
 ** @return Returns @c true for successfully locking the mutex and @c false for
 ** failing
 **/
i_DECLIMEX_ char rfMutex_Lock(RF_Mutex* m);

/**
 ** @memberof RF_Mutex
 ** @brief Locks the mutex but with a time limit
 **
 ** This function works in the same fashion as the @ref rfMutex_Lock() function
 ** except that if the mutex is already locked then the calling thread is
 ** suspended only for the amount of time given as the argument to this function
 ** @param[in] m The mutex in question
 ** @param[in[ ms The milliseconds to wait for the mutex to unlock if
 ** it's already locked
 ** @param[out] expire A flag denoting if @c ms millisecons have passed 
 ** without being able to acquire the mutex. Check for this to be @c true 
 ** if the function fails
 ** @return Returns @c true for successfully locking the mutex and @c false for
 ** failing
 **/
i_DECLIMEX_ char rfMutex_TimedLock(RF_Mutex* m, uint32_t ms, char* expire);

/**
 ** @memberof RF_Mutex
 ** @brief Tries to Lock the mutex
 **
 ** If the mutex is already locked by another thread then an error code is returned.
 ** @param[in] m The mutex in question
 ** @oaram[out] busy A flag denoting if the mutex is already locked by another
 ** thread 
 ** @return Returns @c true for successfully locking the mutex and @c false for
 ** failing
 **/
i_DECLIMEX_ char rfMutex_TryLock(RF_Mutex* m, char* busy);

/**
 ** @memberof RF_Mutex
 ** @brief Unlocks and releases ownership of a mutex object
 ** @param m The mutex in question
 ** Returns @c true in succesfull release and @c false otherwise
 **/
i_DECLIMEX_  char rfMutex_Unlock(RF_Mutex* m);

#ifdef __cplusplus
}///closing bracket for calling from C++
#endif

#endif//include guards end
