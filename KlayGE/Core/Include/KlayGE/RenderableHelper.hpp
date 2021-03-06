// RenderableHelper.hpp
// KlayGE 一些常用的可渲染对象 头文件
// Ver 3.9.0
// 版权所有(C) 龚敏敏, 2005-2010
// Homepage: http://www.klayge.org
//
// 3.10.0
// RenderableSkyBox和RenderableHDRSkyBox增加了Technique() (2010.1.4)
//
// 3.9.0
// 增加了RenderableHDRSkyBox (2009.5.4)
//
// 2.7.1
// 增加了RenderableHelper基类 (2005.7.10)
//
// 2.6.0
// 增加了RenderableSkyBox (2005.5.26)
//
// 2.5.0
// 增加了RenderablePoint，RenderableLine和RenderableTriangle (2005.4.13)
//
// 2.4.0
// 初次建立 (2005.3.22)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _RENDERABLEHELPER_HPP
#define _RENDERABLEHELPER_HPP

#pragma once

#include <KlayGE/PreDeclare.hpp>
#include <KlayGE/Renderable.hpp>
#include <KFL/AABBox.hpp>

namespace KlayGE
{
	class KLAYGE_CORE_API RenderableHelper : public Renderable
	{
	public:
		explicit RenderableHelper(std::wstring const & name);
		virtual ~RenderableHelper()
		{
		}

		virtual RenderLayout& GetRenderLayout() const;

		virtual AABBox const & PosBound() const;
		virtual AABBox const & TexcoordBound() const;

		virtual std::wstring const & Name() const;

	protected:
		std::wstring name_;

		AABBox pos_aabb_;
		AABBox tc_aabb_;

		RenderLayoutPtr rl_;

		RenderEffectParameter* color_ep_;
	};

	class KLAYGE_CORE_API RenderablePoint : public RenderableHelper
	{
	public:
		explicit RenderablePoint();
		RenderablePoint(float3 const & v, Color const & clr);
		virtual ~RenderablePoint()
		{
		}

		void SetPoint(float3 const & v);
		void SetColor(Color const & clr);

		void OnRenderBegin();

	private:
		void Init();

	private:
		RenderEffectParameter* v0_ep_;
	};

	class KLAYGE_CORE_API RenderableLine : public RenderableHelper
	{
	public:
		explicit RenderableLine();
		RenderableLine(float3 const & v0, float3 const & v1, Color const & clr);
		virtual ~RenderableLine()
		{
		}

		void SetLine(float3 const & v0, float3 const & v1);
		void SetColor(Color const & clr);

		void OnRenderBegin();

	private:
		void Init();

	private:
		RenderEffectParameter* v0_ep_;
		RenderEffectParameter* v1_ep_;
	};

	class KLAYGE_CORE_API RenderableTriangle : public RenderableHelper
	{
	public:
		explicit RenderableTriangle();
		RenderableTriangle(float3 const & v0, float3 const & v1, float3 const & v2, Color const & clr);
		virtual ~RenderableTriangle()
		{
		}

		void SetTriangle(float3 const & v0, float3 const & v1, float3 const & v2);
		void SetColor(Color const & clr);

		void OnRenderBegin();

	private:
		void Init();

	private:
		RenderEffectParameter* v0_ep_;
		RenderEffectParameter* v1_ep_;
		RenderEffectParameter* v2_ep_;
	};

	class KLAYGE_CORE_API RenderableTriBox : public RenderableHelper
	{
	public:
		explicit RenderableTriBox();
		RenderableTriBox(OBBox const & obb, Color const & clr);
		virtual ~RenderableTriBox()
		{
		}

		void SetBox(OBBox const & obb);
		void SetColor(Color const & clr);

		void OnRenderBegin();

	private:
		void Init();

	private:
		RenderEffectParameter* v0_ep_;
		RenderEffectParameter* v1_ep_;
		RenderEffectParameter* v2_ep_;
		RenderEffectParameter* v3_ep_;
		RenderEffectParameter* v4_ep_;
		RenderEffectParameter* v5_ep_;
		RenderEffectParameter* v6_ep_;
		RenderEffectParameter* v7_ep_;
	};

	class KLAYGE_CORE_API RenderableLineBox : public RenderableHelper
	{
	public:
		explicit RenderableLineBox();
		RenderableLineBox(OBBox const & obb, Color const & clr);
		virtual ~RenderableLineBox()
		{
		}

		void SetBox(OBBox const & obb);
		void SetColor(Color const & clr);

		void OnRenderBegin();

	private:
		void Init();

	private:
		RenderEffectParameter* v0_ep_;
		RenderEffectParameter* v1_ep_;
		RenderEffectParameter* v2_ep_;
		RenderEffectParameter* v3_ep_;
		RenderEffectParameter* v4_ep_;
		RenderEffectParameter* v5_ep_;
		RenderEffectParameter* v6_ep_;
		RenderEffectParameter* v7_ep_;
	};

	class KLAYGE_CORE_API RenderablePlane : public RenderableHelper
	{
	public:
		RenderablePlane(float length, float width, int length_segs, int width_segs,
			bool has_tex_coord, bool has_tangent);
		virtual ~RenderablePlane()
		{
		}
	};

	class KLAYGE_CORE_API RenderDecal : public RenderableHelper
	{
	public:
		RenderDecal(TexturePtr const & normal_tex, TexturePtr const & albedo_tex,
			float3 const & albedo_clr, float metalness, float glossiness);

		void OnRenderBegin();

	private:
		RenderEffectParameter* inv_mv_ep_;
		RenderEffectParameter* g_buffer_rt0_tex_param_;
		float3 albedo_clr_;
		float metalness_;
		float glossiness_;
	};
}

#endif		// _RENDERABLEHELPER_HPP
