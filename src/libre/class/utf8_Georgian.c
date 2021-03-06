/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Georgian_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[7] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 7; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xe1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xe2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[5], 0x82)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[6], 0x83)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[3], 0xb4)) { goto error; }
	for (i = 0x80; i <= 0xa5; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[3], s[4], 0xa7)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[4], 0xad)) { goto error; }
	for (i = 0xa0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[4], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x85; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[6], s[4], 0x87)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[6], s[4], 0x8d)) { goto error; }
	for (i = 0x90; i <= 0xba; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}
	for (i = 0xbc; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[4], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

