/* bzflag
 * Copyright (c) 1993 - 2008 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

// interface headers
#include "HUDuiNestedContainer.h"

// common implementation headers
#include "HUDNavigationQueue.h"

//
// HUDuiNestedContainer
//

HUDuiNestedContainer::HUDuiNestedContainer() : HUDuiControl()
{
  // Do nothing
}

HUDuiNestedContainer::~HUDuiNestedContainer()
{
  // Do nothing
}

void HUDuiNestedContainer::addControl(HUDuiControl *control)
{
  nestedNavList.push_back(control);
  control->setNavQueue(&nestedNavList);
  control->isNested(true);
  control->setParent(this);
}

void HUDuiNestedContainer::setNavQueue(HUDNavigationQueue* _navList)
{
  HUDuiControl::setNavQueue(_navList);
  _navList->setCallback(gotFocus, this);
}

size_t HUDuiNestedContainer::gotFocus(size_t oldFocus, size_t proposedFocus, HUDNavChangeMethod changeMethod, void* data)
{
  // This should probably grab the selected item in the container and set that to focus
  // Right now this is just a place-holder to get the focus set correctly when it first starts
  ((HUDuiNestedContainer*)data)->getNav().set((size_t)0);
  return ~0;
}

//void HUDuiNestedContainer::initNavigation()
//{
//  for (HUDNavigationQueue::iterator itr = navList.begin(); itr != navList.end(); ++itr)
//    (*itr)->setNavQueue(&navList);
//  navList.set((size_t)0);
//}

// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
