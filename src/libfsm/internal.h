/*
 * Copyright 2008-2017 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#ifndef FSM_INTERNAL_H
#define FSM_INTERNAL_H

#include <limits.h>
#include <stdlib.h>

#include <fsm/fsm.h>
#include <fsm/options.h>

struct edge_set;
struct state_set;

/*
 * The alphabet (Sigma) for libfsm's FSM is arbitrary octets.
 * These octets may or may not spell out UTF-8 sequences,
 * depending on the context in which the FSM is used.
 *
 * Octets are implemented here as (unsigned char) values in C.
 * As an implementation detail, we extend this range from 0..UCHAR_MAX
 * to include "special" edge types after the last valid octet.
 *
 * Currently the only special edge type is the epsilon transition,
 * for Thompson NFA.
 */

/*
 * The number of non-special symbols in the alphabet.
 * This is the number of symbols with the value <= UCHAR_MAX.
 */
#define FSM_SIGMA_COUNT (UCHAR_MAX + 1)

enum fsm_edge_type {
	FSM_EDGE_EPSILON = UCHAR_MAX + 1
};

/*
 * The highest value of an symbol, including special symbols.
 */
#define FSM_EDGE_MAX FSM_EDGE_EPSILON

#define FSM_ENDCOUNT_MAX ULONG_MAX

struct fsm_edge {
	struct state_set *sl;
	enum fsm_edge_type symbol;
};

struct fsm_state {
	unsigned int end:1;

	struct edge_set *edges; /* containing `struct fsm_edge *` */

	void *opaque;

	/* temporary relation between one FSM and another;
	 * meaningful within one particular transformation only */
	struct fsm_state *equiv;

#ifdef DEBUG_TODFA
	struct set *nfasl;
#endif

	struct fsm_state *next;
};

struct fsm {
	struct fsm_state *sl;
	struct fsm_state **tail; /* tail of .sl */
	struct fsm_state *start;

	unsigned long endcount;

	const struct fsm_options *opt;

#ifdef DEBUG_TODFA
	struct fsm *nfa;
#endif
};

struct fsm_edge *
fsm_hasedge(const struct fsm_state *s, int c);

struct fsm_edge *
fsm_addedge(struct fsm_state *from, struct fsm_state *to, enum fsm_edge_type type);

void
fsm_carryopaque(struct fsm *fsm, const struct state_set *set,
	struct fsm *new, struct fsm_state *state);

#endif

