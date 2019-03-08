
/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_PERCPU_RWSEM_H
#define _LINUX_PERCPU_RWSEM_H

#include <pthread.h>
#include <linux/preempt.h>

struct percpu_rw_semaphore {
	pthread_mutex_t		lock;
};

static inline void percpu_down_read_preempt_disable(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_lock(&sem->lock);
}

static inline void percpu_down_read(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_lock(&sem->lock);
}

static inline void percpu_up_read_preempt_enable(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_unlock(&sem->lock);
}

static inline void percpu_up_read(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_unlock(&sem->lock);
}

static inline void percpu_down_write(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_lock(&sem->lock);
}

static inline void percpu_up_write(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_unlock(&sem->lock);
}

static inline void percpu_free_rwsem(struct percpu_rw_semaphore *sem) {}

static inline int percpu_init_rwsem(struct percpu_rw_semaphore *sem)
{
	pthread_mutex_init(&sem->lock, NULL);
	return 0;
}

#define percpu_rwsem_assert_held(sem)		do {} while (0)

#endif
