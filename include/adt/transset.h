/*
 * Copyright 2019 Shannon F. Stewman
 *
 * See LICENCE for the full copyright terms.
 */

#ifndef ADT_TRANSSET_H
#define ADT_TRANSET_H

struct trans_set;
struct trans;

struct trans_iter {
	struct set_iter iter;
};

struct trans_set *
trans_set_create(int (*cmp)(const void *a, const void *b));

void
trans_set_free(struct trans_set *set);

struct trans *
trans_set_add(struct trans_set *set, struct trans *item);

struct trans *
trans_set_contains(const struct trans_set *set, const struct trans *item);

void
trans_set_clear(struct trans_set *set);

struct trans *
trans_set_first(const struct trans_set *set, struct trans_iter *it);

struct trans *
trans_set_next(struct trans_iter *it);

#endif

