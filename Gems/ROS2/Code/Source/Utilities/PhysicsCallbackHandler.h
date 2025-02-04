/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once
#include <AzCore/Component/Entity.h>
#include <AzFramework/Physics/Common/PhysicsEvents.h>
#include <AzFramework/Physics/PhysicsSystem.h>

namespace ROS2::Utils
{
    //! Helper class that register OnSceneSimulationFinishHandler and retrieve handle to Simulated Body from the Default Scene.
    class PhysicsCallbackHandler
    {
    protected:
        //! Install to default physics scene callbacks, when the scene is created, the @member m_bodyHandle is populated with the handle to
        //! simulated body.
        //! @param m_entityId Entity id to get m_bodyHandle to.
        void InstallPhysicalCallback(AZ::EntityId m_entityId);

        //! Removes all attached callbacks
        void RemovePhysicalCallback();

        //! Called multiple times per frame after every inner loop of physics engine.
        //! It virtual version of  callback AzPhysics::SceneEvents::OnSceneSimulationFinishHandler.
        //! @param sceneHandle - scene handle, only handle to Default Scene is expected
        //! @param deltaTime - update of simulated time in seconds.
        virtual void OnPhysicsSimulationFinished(AzPhysics::SceneHandle sceneHandle, float deltaTime) {};

        //! Callback called on begging of the first physical simulation.
        //! inner loop of physics engine.
        //! @param sceneHandle - scene handle, only handle to Default Scene is expected
        virtual void OnPhysicsInitialization(AzPhysics::SceneHandle sceneHandle) {};

        //! Handler to simulated physical body
        AzPhysics::SimulatedBodyHandle m_bodyHandle = AzPhysics::InvalidSimulatedBodyHandle;
    private:
        AzPhysics::SceneEvents::OnSceneSimulationFinishHandler m_onSceneSimulationEvent;
        AzPhysics::SceneEvents::OnSceneSimulationStartHandler m_onSceneSimulationStart;
    };
} // namespace ROS2::Utils
