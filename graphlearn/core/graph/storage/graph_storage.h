/* Copyright 2020 Alibaba Group Holding Limited. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef GRAPHLEARN_CORE_GRAPH_STORAGE_GRAPH_STORAGE_H_
#define GRAPHLEARN_CORE_GRAPH_STORAGE_GRAPH_STORAGE_H_

#include <cstdint>
#include <string>
#include <vector>
#include "graphlearn/core/graph/storage/types.h"

namespace graphlearn {
namespace io {

class GraphStorage {
public:
  virtual ~GraphStorage() = default;

  virtual void Lock() = 0;
  virtual void Unlock() = 0;

  virtual void Build() = 0;

  virtual void SetSideInfo(const SideInfo* info) = 0;
  virtual const SideInfo* GetSideInfo() const = 0;

  virtual void Add(EdgeValue* value) = 0;

  virtual IdType GetEdgeCount() const = 0;
  virtual IdType GetSrcId(IdType edge_id) const = 0;
  virtual IdType GetDstId(IdType edge_id) const = 0;
  virtual IndexType GetEdgeLabel(IdType edge_id) const = 0;
  virtual float GetEdgeWeight(IdType edge_id) const = 0;
  virtual const Attribute* GetEdgeAttribute(IdType edge_id) const = 0;

  virtual const IdList* GetNeighbors(IdType src_id) const = 0;
  virtual const IdList* GetOutEdges(IdType src_id) const = 0;

  virtual IndexType GetInDegree(IdType dst_id) const = 0;
  virtual IndexType GetOutDegree(IdType src_id) const = 0;
  virtual const IndexList* GetAllInDegrees() const = 0;
  virtual const IndexList* GetAllOutDegrees() const = 0;
  virtual const IdList* GetAllSrcIds() const = 0;
  virtual const IdList* GetAllDstIds() const = 0;
};

GraphStorage* NewMemoryGraphStorage();

}  // namespace io
}  // namespace graphlearn

#endif  // GRAPHLEARN_CORE_GRAPH_STORAGE_GRAPH_STORAGE_H_