using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LifeCycle : MonoBehaviour
{

    Rigidbody rigid;

    void Start()
    {
        rigid = GetComponent<Rigidbody>();
        //rigid.velocity = new Vector3(2, 4, 0);
        //rigid.AddForce(Vector3.up * 5, ForceMode.Impulse);
    }
    void FixedUpdate()
    {
        //Vector3 vec = new Vector3(
        //    Input.GetAxisRaw("Horizontal") * Time.deltaTime,
        //    Input.GetAxisRaw("Vertical") * Time.deltaTime);
        //transform.Translate(vec);
        //rigid.velocity = new Vector3(2, 4, 0);
        if (Input.GetButtonDown("Jump"))
        {
            rigid.AddForce(Vector3.up * 5, ForceMode.Impulse);
        }
        Vector3 vec = new Vector3(
        Input.GetAxisRaw("Horizontal"), 0,
        Input.GetAxisRaw("Vertical"));
        rigid.AddForce(vec, ForceMode.Impulse);
        //rigid.AddTorque(Vector3.forward);
    }
    private void OnTriggerStay(Collider other)
    {
        if(other.name == "Cube" )
        {
            rigid.AddForce(Vector3.up, ForceMode.Impulse);
        }
    }
    public void Jump()
    {
        rigid.AddForce(Vector3.up * 20, ForceMode.Impulse);
    }
}
