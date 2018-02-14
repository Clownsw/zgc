/*
 * Copyright (c) 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#ifndef SHARE_GC_Z_ZFLAGS_HPP
#define SHARE_GC_Z_ZFLAGS_HPP

#include "runtime/globals.hpp"

#define Z_FLAGS(develop,       \
                develop_pd,    \
                product,       \
                product_pd,    \
                diagnostic,    \
                diagnostic_pd, \
                experimental,  \
                notproduct,    \
                manageable,    \
                product_rw,    \
                range,         \
                constraint,    \
                writeable)     \
                                                                            \
  product(bool, UseZGC, false,                                              \
          "Use the Z garbage collector")                                    \
                                                                            \
  product(bool, UseLoadBarrier, false,                                      \
          "Use load barrier on all reference loads")                        \
                                                                            \
  product(ccstr, ZPath, NULL,                                               \
          "Filesystem path for Java heap backing storage "                  \
          "(must be a tmpfs or a hugetlbfs filesystem)")                    \
                                                                            \
  product(double, ZAllocationSpikeTolerance, 2.0,                           \
          "Allocation spike tolerance factor")                              \
                                                                            \
  product(double, ZFragmentationLimit, 25.0,                                \
          "Maximum allowed heap fragmentation")                             \
                                                                            \
  product(bool, ZStallOnOutOfMemory, true,                                  \
          "Allow Java threads to stall and wait for GC to complete "        \
          "instead of immediately throwing an OutOfMemoryError")            \
                                                                            \
  product(uint, ZCollectionInterval, 0,                                     \
          "Time between GCs (in seconds)")                                  \
                                                                            \
  product(uint, ZStatisticsInterval, 10,                                    \
          "Time between statistics print outs (in seconds)")                \
          range(1, (uint)-1)                                                \
                                                                            \
  product(bool, ZStatisticsForceTrace, false,                               \
          "Force tracing of ZStats")                                        \
                                                                            \
  product(bool, ZUnmapBadViews, false,                                      \
          "Unmap bad address views (for debugging only)")                   \
                                                                            \
  product(bool, ZVerifyMarking, false,                                      \
          "Verify marking stacks (for debugging only)")                     \
                                                                            \
  product(bool, ZVerifyForwarding, false,                                   \
          "Verify forwarding tables (for debugging only)")                  \
                                                                            \
  product(bool, ZWeakRoots, true,                                           \
          "Treat JNI WeakGlobalRefs and StringTable as weak roots "         \
          "(for debugging only)")                                           \
                                                                            \
  product(bool, ZConcurrentJNIWeakGlobalHandles, true,                      \
          "Clean JNI WeakGlobalRefs concurrently (for debugging only)")     \
                                                                            \
  product(size_t, ZMarkStacksMax, NOT_LP64(512*M) LP64_ONLY(8*G),           \
          "Maximum number of bytes allocated for marking stacks")           \
          range(32*M, NOT_LP64(512*M) LP64_ONLY(1024*G))                    \

Z_FLAGS(DECLARE_DEVELOPER_FLAG,     \
        DECLARE_PD_DEVELOPER_FLAG,  \
        DECLARE_PRODUCT_FLAG,       \
        DECLARE_PD_PRODUCT_FLAG,    \
        DECLARE_DIAGNOSTIC_FLAG,    \
        DECLARE_PD_DIAGNOSTIC_FLAG, \
        DECLARE_EXPERIMENTAL_FLAG,  \
        DECLARE_NOTPRODUCT_FLAG,    \
        DECLARE_MANAGEABLE_FLAG,    \
        DECLARE_PRODUCT_RW_FLAG,    \
        IGNORE_RANGE,               \
        IGNORE_CONSTRAINT,          \
        IGNORE_WRITEABLE)

#endif // SHARE_GC_Z_ZFLAGS_HPP
