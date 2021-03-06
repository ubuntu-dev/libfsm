/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Hebrew_fsm(const struct fsm_options *opt)
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

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xd6)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xd7)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xef)) { goto error; }
	for (i = 0x91; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[1], s[4], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x87; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { goto error; }
	}
	for (i = 0x90; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { goto error; }
	}
	for (i = 0xb0; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[3], s[5], 0xac)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[6], 0xad)) { goto error; }
	for (i = 0x9d; i <= 0xb6; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[4], i)) { goto error; }
	}
	for (i = 0xb8; i <= 0xbc; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[4], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[5], s[4], 0xbe)) { goto error; }
	for (i = 0x80; i <= 0x81; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}
	for (i = 0x83; i <= 0x84; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}
	for (i = 0x86; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[4], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[4], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

