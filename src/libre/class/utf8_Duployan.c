/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Duployan_fsm(const struct fsm_options *opt)
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

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xf0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0x9b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[3], 0xb0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0xb1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[5], 0xb2)) { goto error; }
	for (i = 0x80; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[6], i)) { goto error; }
	}
	for (i = 0xb0; i <= 0xbc; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x88; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { goto error; }
	}
	for (i = 0x90; i <= 0x99; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { goto error; }
	}
	for (i = 0x9c; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[6], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}
