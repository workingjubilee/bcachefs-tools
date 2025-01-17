#ifndef __TOOLS_LINUX_SRCU_H
#define __TOOLS_LINUX_SRCU_H

#include <linux/rcupdate.h>

#define NUM_ACTIVE_RCU_POLL_OLDSTATE	2

typedef void (*rcu_callback_t)(struct rcu_head *head);

struct srcu_struct {
};

static inline void srcu_read_unlock(struct srcu_struct *ssp, int idx) {}

static inline int srcu_read_lock(struct srcu_struct *ssp)
{
	return 0;
}

static inline bool poll_state_synchronize_srcu(struct srcu_struct *ssp, unsigned long cookie)
{
	return false;
}

static inline unsigned long start_poll_synchronize_srcu(struct srcu_struct *ssp)
{
	return 0;
}

static inline unsigned long get_state_synchronize_srcu(struct srcu_struct *ssp)
{
	return 0;
}

#undef poll_state_synchronize_rcu
static inline bool poll_state_synchronize_rcu(unsigned long cookie)
{
	return false;
}

#undef start_poll_synchronize_rcu
static inline unsigned long start_poll_synchronize_rcu()
{
	return 0;
}

static inline unsigned long get_state_synchronize_rcu()
{
	return 0;
}

static inline void synchronize_srcu_expedited(struct srcu_struct *ssp) {}

static inline void srcu_barrier(struct srcu_struct *ssp) {}

static inline void cleanup_srcu_struct(struct srcu_struct *ssp) {}

static inline void call_srcu(struct srcu_struct *ssp, struct rcu_head *rhp,
			     rcu_callback_t func)
{
	func(rhp);
}

static inline int init_srcu_struct(struct srcu_struct *ssp)
{
	return 0;
}

#endif /* __TOOLS_LINUX_SRCU_H */
