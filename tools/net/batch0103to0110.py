#!/usr/bin/env python
# Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
# Copyright (C) 2009-2018 German Aerospace Center (DLR) and others.
# This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v20.html

# @file    batch0103to0110.py
# @author  Daniel Krajzewicz
# @author  Michael Behrisch
# @date    2007
# @version $Id$

"""
Applies the transformation on all nets in the given folder or
 - if no folder is given - in the base folder (../..).
"""
from __future__ import absolute_import
from __future__ import print_function

import os
import os.path
import sys

r = "../../"
if len(sys.argv) > 1:
    r = sys.argv[1]
srcRoot = os.path.join(os.path.dirname(sys.argv[0]), r)
for root, dirs, files in os.walk(srcRoot):
    for name in files:
        if name.endswith(".net.xml") or name == "net.netconvert" or name == "net.netgen":
            p = os.path.join(root, name)
            print("Patching " + p + "...")
            os.system("0103to0110.py " + p)
            os.remove(p)
            os.rename(p + ".chg", p)
        for ignoreDir in ['.svn', 'foreign']:
            if ignoreDir in dirs:
                dirs.remove(ignoreDir)
