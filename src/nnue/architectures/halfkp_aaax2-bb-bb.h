/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2020 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Definition of input features and network structure used in NNUE evaluation function

#ifndef NNUE_HALFKP_GENERIC_DEFINED
#define NNUE_HALFKP_GENERIC_DEFINED

#include "../features/feature_set.h"
#include "../features/half_kp.h"

#include "../layers/input_slice.h"
#include "../layers/affine_transform.h"
#include "../layers/clipped_relu.h"

namespace Eval::NNUE {

// Input features used in evaluation function
using RawFeatures = Features::FeatureSet<
    Features::HalfKP<Features::Side::kFriend>>;

// Number of input feature dimensions after conversion
constexpr IndexType kTransformedFeatureDimensions = NN_TRANSFORMED_FEATURE_DIMENSIONS;

namespace Layers {

// Define network structure
using InputLayer = InputSlice<kTransformedFeatureDimensions * 2>;
using HiddenLayer1 = ClippedReLU<AffineTransform<InputLayer, NN_NET_WIDTH>>;
using HiddenLayer2 = ClippedReLU<AffineTransform<HiddenLayer1, NN_NET_WIDTH>>;
using OutputLayer = AffineTransform<HiddenLayer2, 1>;

}  // namespace Layers

using Network = Layers::OutputLayer;

}  // namespace Eval::NNUE

#endif // #ifndef NNUE_HALFKP_GENERIC_DEFINED
