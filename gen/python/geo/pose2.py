# -----------------------------------------------------------------------------
# This file was autogenerated by symforce. Do NOT modify by hand.
# -----------------------------------------------------------------------------
import numpy as np

from .rot2 import Rot2
from .ops import pose2 as ops


class Pose2(object):
    """"
    Autogenerated Python implementation of <class 'symforce.geo.pose2.Pose2'>.

    Group of two-dimensional rigid body transformations - SE(2).

    The storage space is a complex (real, imag) for rotation followed by a position (x, y).

    The tangent space is two elements for translation followed by one angle for rotation.
    TODO(hayk): Flip this to match Pose3 with rotation first.
    """

    __slots__ = ['data']

    def __repr__(self):
        return '<{} {}>'.format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        return 4

    def to_storage(self):
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        instance = cls()

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        assert len(vec) == cls.storage_dim(), '{} has storage dim {}, got {}.'.format(
            cls.__name__, cls.storage_dim(), len(vec))

        return instance

    # --------------------------------------------------------------------------
    # GroupOps concept
    # --------------------------------------------------------------------------

    @classmethod
    def identity(cls):
        return cls.from_storage(ops.GroupOps.identity())

    def inverse(self):
        return self.__class__.from_storage(ops.GroupOps.inverse(self))

    def compose(self, b):
        return self.__class__.from_storage(ops.GroupOps.compose(self, b))

    def between(self, b):
        return self.__class__.from_storage(ops.GroupOps.between(self, b))

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        return 3

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        assert len(vec) == cls.tangent_dim(), '{}, {}'.format(len(vec), cls.tangent_dim())
        return cls.from_storage(ops.LieGroupOps.from_tangent(vec, epsilon))

    def to_tangent(self, epsilon=1e-8):
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        assert len(vec) == self.tangent_dim(), '{}, {}'.format(len(vec), self.tangent_dim())
        return self.__class__.from_storage(ops.LieGroupOps.retract(self, vec, epsilon))

    def local_coordinates(self, b, epsilon=1e-8):
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        return self.data == other.data

    def __mul__(self, other):
        if isinstance(other, self.__class__):
            return self.compose(other)
        else:
            raise NotImplementedError('Cannot compose {} with {}.'.format(type(self), type(other)))

    # Included from "custom_methods/pose2.py":
    # --------------------------------------------------------------------------
    # Handwritten methods for Pose2
    # These will get included into the autogenerated class header.
    # --------------------------------------------------------------------------

    def __init__(self, R=None, t=None):
        rotation = R if R is not None else Rot2()
        position = t if R is not None else [0., 0.]
        assert isinstance(rotation, Rot2)

        self.data = rotation.to_storage() + list(position)

    def rotation(self):
        return Rot2.from_storage(self.data[0:2])

    def position(self):
        return np.array(self.data[2:4])
