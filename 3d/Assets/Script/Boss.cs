using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Boss : Enemy
{
    public GameObject missile;
    public Transform missilePortA;
    public Transform missilePortB;

    Vector3 lookVec;
    Vector3 tauntVec;
    bool isLook;
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        boxCollider = GetComponent<BoxCollider>();
        meshs = GetComponentsInChildren<MeshRenderer>();
        //Material은 MeshRenderer에서 접근가능
        nav = GetComponent<NavMeshAgent>();
        anim = GetComponentInChildren<Animator>();
        StartCoroutine(Think());
    }
    void Update()
    {
        if(isLook)
        {
            float h = Input.GetAxisRaw("Horizontal");
            float v = Input.GetAxisRaw("Vertical");
            lookVec = new Vector3(h, 0, v) * 5f;
            transform.LookAt(target.position + lookVec);
        }
    }
    IEnumerator Think()
    {
        yield return new WaitForSeconds(0.1f);

        int ranAction = Random.Range(0, 5);
        switch(ranAction)
        {
            case 0:
            case 1:
                StartCoroutine(MissileShot());
                //미사일 발사 패턴
                break;
            case 2:
            case 3:
                StartCoroutine(RockShot());
                //돌 굴러가는 패턴
                break;
            case 4:
                StartCoroutine(Taunt());
                //점프 공격 패턴
                break;            
        }
    }
    IEnumerator MissileShot()
    {
        anim.SetTrigger("doShot");
        yield return new WaitForSeconds(2.5f);
        StartCoroutine(Think());
    }
    IEnumerator RockShot()
    {
        anim.SetTrigger("doBigShot");
        yield return new WaitForSeconds(3f);
        StartCoroutine(Think());
    }
    IEnumerator Taunt()
    {
        anim.SetTrigger("doTaunt");
        yield return new WaitForSeconds(3f);
        StartCoroutine(Think());
    }
}
