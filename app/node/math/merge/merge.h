/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2021 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef MERGENODE_H
#define MERGENODE_H

#include "node/node.h"

namespace olive {

class MergeNode : public Node
{
  Q_OBJECT
public:
  MergeNode();

  NODE_DEFAULT_DESTRUCTOR(MergeNode)

  virtual Node* copy() const override;

  virtual QString Name() const override;
  virtual QString id() const override;
  virtual QVector<CategoryID> Category() const override;
  virtual QString Description() const override;

  virtual void Retranslate() override;

  virtual ShaderCode GetShaderCode(const QString &shader_id) const override;
  virtual void Value(const NodeValueRow& value, const NodeGlobals &globals, NodeValueTable *table) const override;

  static const QString kBaseIn;
  static const QString kBlendIn;

  virtual void Hash(const ValueHint& output, QCryptographicHash &hash, const NodeGlobals &globals, const VideoParams& video_params) const override;

private:
  NodeInput* base_in_;

  NodeInput* blend_in_;

};

}

#endif // MERGENODE_H
