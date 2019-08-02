/*
 * This addon adds Tiled map support to the Allegro game library.
 * Copyright (c) 2012-2014 Damien Radtke - www.damienradtke.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source
 *    distribution.
 */

#ifndef _XML_H
#define _XML_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_tiled.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <glib.h>

GSList *get_children_for_name(xmlNode *parent, char *name);
GSList *get_children_for_either_name(xmlNode *parent, char *name1, char *name2);
xmlNode *get_first_child_for_name(xmlNode *parent, char *name);
char *get_xml_attribute(xmlNode *node, char *name);

#endif
