/* bzflag
 * Copyright (c) 1993 - 2003 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "callbacks.h"
#include "LocalPlayer.h"
#include "HUDRenderer.h"

extern LocalPlayer*	myTank;
extern HUDRenderer*	hud;

void setFlagHelp(const std::string& name, void*)
{
  if (myTank == NULL)
    return;
  static const float FlagHelpDuration = 60.0f;
  if (BZDB.isTrue(name))
    hud->setFlagHelp(myTank->getFlag(), FlagHelpDuration);
  else
    hud->setFlagHelp(Flags::Null, 0.0);
}

void setDepthBuffer(const std::string&, void*)
{
  /* FIXME - time dependant callback is not safe.  cannot make
   * ogl call until the pipeline/context is initialized, whereas
   * this callback is made when zbuffer is set in config file.
   * that can crash a client.
   */
#if 0
  /* if zbuffer was set and not available, unset it */
  if (BZDB.isTrue(name)) {
    GLint value;
    glGetIntegerv(GL_DEPTH_BITS, &value);
    if (value == 0) {
      // temporarily remove ourself
      BZDB.removeCallback(name, setDepthBuffer, NULL);
      BZDB.set(name, "0");
      // add it again
      BZDB.addCallback(name, setDepthBuffer, NULL);
    }
  }
#endif
}

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

