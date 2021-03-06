/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Nushu_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[9] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 9; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xf0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0x96)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0x9b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0xbf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[6], 0x85)) { goto error; }
	for (i = 0x86; i <= 0x8a; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[7], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[3], s[8], 0x8b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[4], s[5], 0xa1)) { goto error; }
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[5], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[5], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xbb; i++) {
		if (!fsm_addedge_literal(fsm, s[8], s[5], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[5], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

