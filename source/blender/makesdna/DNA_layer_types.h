/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Dalai Felinto
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file DNA_layer_types.h
 *  \ingroup DNA
 */

#ifndef __DNA_LAYER_TYPES_H__
#define __DNA_LAYER_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "DNA_listBase.h"

typedef struct ObjectBase {
	struct ObjectBase *next, *prev;
	short flag;
	short refcount;
	struct Object *object;
} ObjectBase;

typedef struct CollectionOverride {
	struct CollectionOverride *next, *prev;
	char name[64]; /* MAX_NAME */
	/* TODO proper data */
} CollectionOverride;

typedef struct CollectionBase {
	struct CollectionBase *next, *prev;
	struct Collection *collection;
	short flag;
	short pad[3];
	ListBase collection_bases; /* synced with collection->collections */
	ListBase object_bases; /* synced with collection->objects and collection->filter_objects */
	ListBase overrides;
} CollectionBase;

typedef struct Collection {
	struct Collection *next, *prev;
	char name[64]; /* MAX_NAME */
	char filter[64]; /* MAX_NAME */
	ListBase collections; /* nested collections */
	ListBase objects;
	ListBase filter_objects;
} Collection;

typedef struct SceneLayer {
	struct SceneLayer *next, *prev;
	char name[64]; /* MAX_NAME */
	char engine[32]; /* render engine */
	short active_collection;
	struct ObjectBase *basact;
	ListBase collection_bases;
	ListBase object_bases;
} SceneLayer;

/* CollectionBase->flag */
enum {
	COLLECTION_VISIBLE    = (1 << 0),
	COLLECTION_SELECTABLE = (1 << 1),
	COLLECTION_FOLDED     = (1 << 2),
};

#ifdef __cplusplus
}
#endif

#endif  /* __DNA_LAYER_TYPES_H__ */

