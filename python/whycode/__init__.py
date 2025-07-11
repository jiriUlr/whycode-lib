from . import whycode_py as _py

__all__ = [
    "RawImage",
    "Whycode",
    "Parameters",
    "Marker",
    "Segment",
    "TrackedObject",
    "D3Transform",
    "CalibrationConfig",
    "TransformType",
]

RawImage = _py.CRawImage
Whycode = _py.CWhycode
Parameters = _py.Parameters
Marker = _py.SMarker
Segment = _py.SSegment
TrackedObject = _py.STrackedObject
D3Transform = _py.S3DTransform
CalibrationConfig = _py.CalibrationConfig
TransformType = _py.ETransformType

# -------------------------------
# Parameters __repr__ and __str__
# -------------------------------

def _repr_parameters(self):
    return (f"Parameters(id_bits={self.id_bits}, id_samples={self.id_samples}, hamming_dist={self.hamming_dist}, "
            f"draw_coords={self.draw_coords}, draw_segments={self.draw_segments}, use_gui={self.use_gui}, identify={self.identify}, "
            f"coords_method={self.coords_method}, num_markers={self.num_markers}, min_size={self.min_size}, "
            f"circle_diameter={self.circle_diameter}, calib_dist_x={self.calib_dist_x}, calib_dist_y={self.calib_dist_y}, "
            f"initial_circularity_tolerance={self.initial_circularity_tolerance}, final_circularity_tolerance={self.final_circularity_tolerance}, "
            f"area_ratio_tolerance={self.area_ratio_tolerance}, center_distance_tolerance_ratio={self.center_distance_tolerance_ratio}, "
            f"center_distance_tolerance_abs={self.center_distance_tolerance_abs})")

Parameters.__repr__ = _repr_parameters
Parameters.__str__ = _repr_parameters

# ----------------------------
# Segment __repr__ and __str__
# ----------------------------

def _repr_segment(self):
    return (f"Segment(x={self.x}, y={self.y}, angle={self.angle}, horizontal={self.horizontal}, "
            f"size={self.size}, maxx={self.maxx}, maxy={self.maxy}, minx={self.minx}, miny={self.miny}, "
            f"mean={self.mean}, type={self.type}, roundness={self.roundness}, bwRatio={self.bwRatio}, "
            f"round={self.round}, valid={self.valid}, m0={self.m0}, m1={self.m1}, "
            f"v0={self.v0}, v1={self.v1}, r0={self.r0}, r1={self.r1}, ID={self.ID})")

Segment.__repr__ = _repr_segment
Segment.__str__ = _repr_segment

# ----------------------------------
# TrackedObject __repr__ and __str__
# ----------------------------------

def _tracked_object_repr(self):
    return (f"TrackedObject(u={self.u}, v={self.v}, x={self.x}, y={self.y}, z={self.z}, "
            f"d={self.d}, roll={self.roll}, pitch={self.pitch}, yaw={self.yaw}, angle={self.angle}, "
            f"n0={self.n0}, n1={self.n1}, n2={self.n2}, "
            f"qx={self.qx}, qy={self.qy}, qz={self.qz}, qw={self.qw})")

TrackedObject.__repr__ = _tracked_object_repr
TrackedObject.__str__ = _tracked_object_repr

# ---------------------------
# Marker __repr__ and __str__
# ---------------------------

def _repr_marker(self):
    return (f"Marker(valid={self.valid}, seg={self.seg}, obj={self.obj})")

Marker.__repr__ = _repr_marker
Marker.__str__ = _repr_marker
